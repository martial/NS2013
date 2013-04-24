var TweenExample = Animation.extend({

    setup: function (s) {


        println("-- Tween chain example.js -- ");

        this._super();

        this.tweens = new Array();
        TWEEN.removeAll();

        this.goMadCount = 0;
        this.openArmsCount = 0;
        this.turtleCount = 0;
        this.cosPct = 0.0;
        this.scene = s;


        // start
        this.initTweens(s);

    },

    update: function (s) {


        // update sharpys properties
        for (var i = 0; i < numSharpy; i++) {

            var tween = this.tweens[i];

            setOrientation  (s, i, tween.pan, tween.tilt, tween.roll);
            setGobo         (s, i, tween.gobo);
            setBrightness   (s, i, tween.brt)

        }

    },

    //-------------------------------------------------------

    initTweens: function (s) {

        //TWEEN.removeAll();

        for (var i = 0; i < 2; i++) {

            for (var j = 0; j < 16; j++) {

                // get index
                var index = i * 16 + j;

                // get simple orientation
                var pan = (i % 2 == 0) ? -45 : 45;

                // set default orientation - be careful It's for testing
                setOrientation(s, index, 0, 0, 0);

                // add a new empty orientation - push it to array

                this.tweens[index] = {brt: 1.0, gobo: 1.0, pan: 0, tilt: 0, roll: 0};

                // declare our tweens !
                // let's rumble the pan titl and gobo.

                var tween = new TWEEN.Tween(this.tweens[index])
                    .to({ pan: pan, gobo: 1.0, tilt: 45, brt: 1.0 }, 500 + (j * 10))
                    .easing(TWEEN.Easing.Quintic.Out)
                    //.onUpdate( function () { // do as you please } )
                    .start();

                // if It's the last one, then goLaser
                if (index == 31) {

                    // be careful to scope
                    var scope = this;
                    tween.onComplete(function () {
                        scope.goLaser();
                    });
                }

            }

        }

    },

    //-------------------------------------------------------

    goLaser: function () {

        for (var i = 0; i < 2; i++) {

            for (var j = 0; j < 16; j++) {

                var index = i * 16 + j;
                var pan = (i % 2 == 0) ? 45 : -45;

                var tween = new TWEEN.Tween(this.tweens[index])
                    .to({pan: pan, gobo: 0.0, tilt: -45}, 300 + (j * 200))
                    .easing(TWEEN.Easing.Quintic.InOut)
                    .start();

            }

            if (index == 31) {
                var scope = this;
                tween.onComplete(function () {
                    scope.goMad()
                });
            }

        }

    },

    //-------------------------------------------------------

    goMad: function () {

        var scope = this;
        for (var i = 0; i < numSharpy; i++) {

            var rdm = Math.random();
            var pan = -45 + (90 * rdm);
            var tilt = -45 + (90 * rdm);
            var roll = -45 + (90 * rdm);
            var speed = 2000 + rdm * 400;

            var tweenObject = this.tweens[i];
            var tween = new TWEEN.Tween(this.tweens[i])
                .to({pan: pan, tilt: tilt, roll: roll}, speed)
                .easing(TWEEN.Easing.Linear.None)
                .onUpdate(strob)
                .start();

            if (i == 31 && this.goMadCount < 4)
                tween.onComplete(function () {
                    scope.goMad()
                });
            else if (i == 31) {
                tween.onComplete(function () {
                    scope.goFront()
                });
                this.goMadCount = 0;
            }
        }

        this.goMadCount++;
    },

    //-------------------------------------------------------

    goFront: function () {

        var scope = this;
        for (var i = 0; i < numSharpy; i++) {

            var tween = new TWEEN.Tween(this.tweens[i])
                .to({pan: 0, tilt: -70, roll: 0}, 2000)
                .easing(TWEEN.Easing.Linear.None)
                .onUpdate(strob)
                .start();

            if (i == 31)
                tween.onComplete(function () {
                    scope.goCloseArms()
                });

        }

    },

    //-------------------------------------------------------

    goCloseArms: function () {

        var scope = this;
        for (var i = 0; i < 2; i++) {

            for (var j = 0; j < 16; j++) {

                var index = i * 16 + j;
                var pan = (i % 2 == 0) ? 12 : -12;

                var tween = new TWEEN.Tween(this.tweens[index])
                    .to({pan: pan, tilt: -70, roll: 0}, 2000)
                    .easing(TWEEN.Easing.Linear.None)
                    .onUpdate(strob)
                    .start();

                if (index == 31)
                    tween.onComplete(function () {
                        scope.goPapillonDeLumiere()
                    });

            }
        }

    },

    //-------------------------------------------------------

    goPapillonDeLumiere: function () {

        var scope = this;
        for (var i = 0; i < 2; i++) {

            for (var j = 0; j < 16; j++) {

                var index = i * 16 + j;
                var pan = (i % 2 == 0) ? -j * 3 : j * 3;

                var tween = new TWEEN.Tween(this.tweens[index])
                    .to({pan: pan, tilt: -70, roll: 0}, 2000)
                    .easing(TWEEN.Easing.Linear.None)
                    .onUpdate(strob)
                    .start();

                if (index == 31 && this.openArmsCount < 4)
                    tween.onComplete(function () {
                        scope.goPapillonDeLumiere()
                    });
                else if (index == 31) {
                    tween.onComplete(function () {
                        scope.goLaser()
                    });
                    this.goMadCount = 0;
                }
            }

        }

        this.openArmsCount++;
    }

});

new TweenExample();

