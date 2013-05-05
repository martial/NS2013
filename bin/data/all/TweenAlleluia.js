var TweenExample = Animation.extend({

    setup: function (s) {

        println("-- Tween Alleluia.js -- ");
        this._super();


        this.tweens = new Array();

        // go !
        this.initTweens(s);

    },

    initTweens: function (s) {

        for (var i = 0; i < numSharpy; i++) {

            this.tweens[i]      = new Object();
            this.tweens[i].x    = 0;
            this.tweens[i].y    = 0;
            this.tweens[i].z    = 0;


            var ahou = getSharpyPos(s, i);


            // nouveau tween sur mon objet
            var tween = new TWEEN.Tween(this.tweens[i])

                // je mappe les valeurs et la durée
                .to({ x: 0, y: ahou.y, z: depth}, 2000 + i * 10)

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
                    scope.goAlleluia();
                });
            }

        }



    },

    goAlleluia : function () {


        for (var i = 0; i < numSharpy; i++) {


            // je prends un x qui fait la longeur
            var xPos = -width + ( i * width * 2 ) / numSharpy;

            var posy =  -height + (horizontalSharpies[i] * height * 2/ 32);


            if ( horizontalSharpies[i] < 16)
                posy = -height + -posy;




            // nouveau tween sur mon objet
            var tween = new TWEEN.Tween(this.tweens[horizontalSharpies[i]])

                // je mappe les valeurs et la durée
                .to({ x: width, y:posy, z: 0 }, 3000 + i * 200)

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


