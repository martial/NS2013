var Random = Animation.extend({

    setup: function (s) {

        println("-- Noise.js -- ");
        this._super();

        for (var i = 0; i < numSharpy; i++) {
            //
        }

    },

    update: function (s) {

        for (var i = 0; i < numSharpy; i++) {

            var index = horizontalSharpies[i];


            var pan = (i % 2 == 0 ) ? 20 : -45;

            setOrientation  (s, index, 0, 0, 0);
            //lookAt          (s, i, 0,0, -300);
            setGobo         (s, i, 0.2);
            this.makeRandom   (s, i );

            // var u = a;

        }



    },

    makeRandom : function (s, index) {

        setBrightness   (s, index, Math.random());

    }

});

new Random();

