var TweenExample = Animation.extend({

    setup: function (s) {

        println("-- Example tween.js -- ");
        this._super();

        // j'instancie un array ou je vais stocker mes tweens
        // je m'en servirais comme des objets pour stocker des variables

        // i.e. tweens[i].x ou tweens[i].blabla whatever you need
        this.tweens = new Array();

        // go !
        this.initTweens();

    },

    initTweens: function () {

        for (var i = 0; i < numSharpy; i++) {

            this.tweens[i]      = new Object();
            this.tweens[i].x    = 0;
            this.tweens[i].y    = 0;
            this.tweens[i].z    = 0;

            // nouveau tween sur mon objet
            var tween = new TWEEN.Tween(this.tweens[i])

                // je mappe les valeurs et la durée
                .to({ x: 0.0, y: 0.0, z: depth }, 2000 + i * 10)

                // je choisis le type d'easing
                .easing(TWEEN.Easing.Quintic.Out)

                // go
                .start();



            // astuce
            // si le dernier tween a fini de s'executer - lancer autre function
            // if It's the last one, then goLaser
            if (i == 31) {

                // be careful to scope
                var scope = this;
                tween.onComplete(function () {
                    scope.goLine();
                });
            }

        }



    },

    goLine : function () {


        for (var i = 0; i < numSharpy; i++) {


            // je prends un x qui fait la longeur
            var xPos = -width + ( i * width * 2 ) / numSharpy;



            // nouveau tween sur mon objet
            var tween = new TWEEN.Tween(this.tweens[horizontalSharpies[i]])

                // je mappe les valeurs et la durée
                .to({ x: xPos, y:0, z: 0 }, 1000 + i * 100)

                // je choisis le type d'easing
                .easing(TWEEN.Easing.Quintic.Out)

                // go
                .start();

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


new TweenExample();


