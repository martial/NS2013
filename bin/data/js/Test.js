var Template = Animation.extend({

    setup: function (s) {

        println("-- Template.js -- ");
        this._super();

        this.tweens = new Array();

        // go !
        this.initTweens(s);

    },

    initTweens: function (s) {

        for (var i = 0; i < numSharpy; i++) {

            if (!this.tweens[i]) {
                this.tweens[i] = new Object();
                this.tweens[i].x = 0;
                this.tweens[i].y = 0;
                this.tweens[i].z = 0;

            }

            var nextPos = getSharpyPos(s, i + 1);

            var tween = new TWEEN.Tween(this.tweens[i])

                .to({ x: nextPos.x, y: nextPos.y, z: depth}, 2000 + i * 10)
                .easing(TWEEN.Easing.Quintic.InOut)

                // go
                .start();

            if (i == 31) {

                var scope = this;
                tween.onComplete(function () {
                    scope.goNext(s);
                });
            }

        }

    }, goNext : function (s) {

        for (var i = 0; i < numSharpy; i++) {

            var nextPos = getSharpyPos(s, i);

            var tween = new TWEEN.Tween(this.tweens[i])
                .to({ x: nextPos.x, y: 0, z: depth}, 2000)
                .easing(TWEEN.Easing.Quintic.InOut)
                .delay(100 + horizontalSharpies[i] * 50)
                .start();

            if (i == 31) {

                // be careful to scope
                var scope = this;
                tween.onComplete(function () {
                    scope.goThird();
                });
            }

        }

    },

    goThird: function (s) {

        for (var i = 0; i < numSharpy; i++) {

            var nextPos = getSharpyPos(s, horizontalSharpies[i + 1]);

            // nouveau tween sur mon objet
            var tween = new TWEEN.Tween(this.tweens[i])

                // je mappe les valeurs et la durée
                .to({ x: 0, y: nextPos.y, z: depth}, 2000)

                // je choisis le type d'easing
                .easing(TWEEN.Easing.Quintic.InOut)
                .delay(100 + horizontalSharpies[i] * 50)
                // go
                .start();

            // astuce
            // si le dernier tween a fini de s'executer - lancer autre function
            // if It's the last one, then goLaser

            if (i == 31) {

                // be careful to scope
                var scope = this;
                tween.onComplete(function () {
                    scope.goFourth();
                });
            }

        }

    },

    goFourth: function (s) {



        for (var i = 0; i < numSharpy; i++) {

           // var nextPos = getSharpyPos(s, horizontalSharpies[i + 1]);

            // nouveau tween sur mon objet
            var tween = new TWEEN.Tween(this.tweens[i])

                // je mappe les valeurs et la durée
                .to({ x: 0, y: 0, z: 0}, 2000)

                // je choisis le type d'easing
                .easing(TWEEN.Easing.Quintic.InOut)
                .delay(100 + horizontalSharpies[i] * 50)
                // go
                .start();

            // astuce
            // si le dernier tween a fini de s'executer - lancer autre function
            // if It's the last one, then goLaser

            if (i == 31) {

                // be careful to scope
                var scope = this;
                tween.onComplete(function () {
                    scope.goFifth();
                });
            }

        }




    },

    goFifth:function (s) {

        for (var i = 0; i < numSharpy; i++) {

            // var nextPos = getSharpyPos(s, horizontalSharpies[i + 1]);

            // nouveau tween sur mon objet
            var tween = new TWEEN.Tween(this.tweens[i])

                // je mappe les valeurs et la durée
                .to({ x: 0, y: 0, z: depth}, 2000)

                // je choisis le type d'easing
                .easing(TWEEN.Easing.Quintic.InOut)
                .delay(100 + horizontalSharpies[i] * 50)
                // go
                .start();

            // astuce
            // si le dernier tween a fini de s'executer - lancer autre function
            // if It's the last one, then goLaser

            if (i == 31) {

                // be careful to scope
                var scope = this;
                tween.onComplete(function () {
                    scope.initTweens();
                });
            }

        }



    },


    update: function (s) {

        // dans la boucle update
        // je recupere mes valeurs de tweens

        for (var i = 0; i < numSharpy; i++) {

            var tween = this.tweens[i];
            lookAt(s, i, tween.x, tween.y, tween.z);

        }

    }




});

new Template();




