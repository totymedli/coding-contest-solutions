// https://play.elevatorsaga.com
{
    init: function(elevators, floors) {
        var me = this;
        
        //Handling floor buttons. If a button pressed on a floor this array will keep track of it so elevators can check which floors have waiting passengers.
        var waitingOnFloor = [];
        this.onUpDownButtonPress = function(direction) {
            waitingOnFloor[this.floorNum()].all = true;
        };
        this.onUpButtonPress = function() {
            waitingOnFloor[this.floorNum()].up = true;
        };
        this.onDownButtonPress = function() {
            waitingOnFloor[this.floorNum()].down = true;
        };
        for (var i = 0; i < floors.length; ++i) {
            var floor = floors[i];
            waitingOnFloor[i] = {"up": false, "down": false, "all": false};
            floor.on("up_button_pressed", me.onUpDownButtonPress);
            floor.on("down_button_pressed", me.onUpDownButtonPress);
            floor.on("up_button_pressed", me.onUpButtonPress);
            floor.on("down_button_pressed", me.onDownButtonPress);
        }

        //Setting up routing for all elevator.
        for (var i = 0; i < elevators.length; ++i) {
            var elevator = elevators[i];
            elevator.id = i;
            elevator.direction = 'up';
            elevator.goingDownIndicator(false);
            elevator.on("floor_button_pressed", function(floorNum) {
                var destinations = this.destinationQueue;
                destinations.push(floorNum);
                destinations.sort(function(a, b){return a - b;});//Order destination integers in ascending.
                if (this.direction == 'up/down') {
                    //Find out if there are destinations both above and below the elevator.
                    for (var destinationNum = 0; destinationNum < destinations.length; ++destinationNum) {
                        //If there is a case when there is a lower and higher destination floor then the current floor then splice the destinations.
                        if ((destinations[destinationNum + 1] !== null) && (destinations[destinationNum] < this.currentFloor()) && (destinations[destinationNum + 1] > this.currentFloor())) {
                            var destinationsAboveFloor = destinations.slice(destinationNum + 1, destinations.length);
                            var destinationsBelowFloor = destinations.slice(0, destinationNum + 1);
                            if (destinationsAboveFloor.length > destinationsBelowFloor.length) {
                                destinations = destinationsAboveFloor.concat(destinationsBelowFloor);
                                this.goingUpIndicator(true);
                                this.goingDownIndicator(false);
                                this.direction = 'up';
                            } else {
                                destinations = destinationsBelowFloor.concat(destinationsAboveFloor);
                                this.goingUpIndicator(false);
                                this.goingDownIndicator(true);
                                this.direction = 'down';
                            }
                        }
                    }
                } else if (this.direction) {
                    
                }
                this.checkDestinationQueue();
            });
            elevator.on("stopped_at_floor", function(floorNum) {
                waitingOnFloor[floorNum].all = false;
            });
            elevator.on("idle", function() {
                var nearestFloor = this.currentFloor();//So it will stay there if there is no floor with waiting passengers.
                var nearestFloorDistance = floors.length + 1;//Big enough distance, so the first floor with waiting passengers will be the nearest floor.
                //Find nearest floor with waiting passengers.
                for (var i = 0; i < floors.length; ++i) {
                    if (waitingOnFloor[i].all) {
                        var examinedFloorDistance = Math.abs(i - this.currentFloor());
                        if (examinedFloorDistance < nearestFloorDistance) {
                            nearestFloor = i;
                            nearestFloorDistance = examinedFloorDistance;
                        }   
                    }
                }
                //If there are no floors with waiting people, then stay there and wait.
                if (nearestFloor == this.currentFloor()) {
                    this.goingUpIndicator(true);
                    this.goingDownIndicator(true);
                } else {
                    if (waitingOnFloor[nearestFloor].up) {
                        this.goingUpIndicator(true);
                        this.goingDownIndicator(false);
                        waitingOnFloor[nearestFloor].up = false;
                    } else {
                        this.goingUpIndicator(false);
                        this.goingDownIndicator(true);
                        waitingOnFloor[nearestFloor].down = false;
                    }
                    if (!waitingOnFloor[nearestFloor].up && !waitingOnFloor[nearestFloor].down) {
                        waitingOnFloor[nearestFloor].all = false;
                    }
                }
                this.goToFloor(nearestFloor);
            });
        }
    },
        update: function(dt, elevators, floors) {
            // We normally don't need to do anything here
        }
}
