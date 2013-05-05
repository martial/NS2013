var WhiteWalker = Animation.extend({

    setup: function (s) {

        println("-- WhiteWalker.js -- ");
        this._super();
        this.noise = new SimplexNoise();


    },

    update: function (s) {


       //println(x)

        for (var i = 0; i < numSharpy; i++) {

            var pct     = this.noise.noiseNormalized(timeMillis / 100000, i);

            println(pct)

            var pan   =  ( 360 * pct);
            var tilt =  -90 + ( 180 * pct);
            setRotation  (s, i, pan,tilt);



        }

    }



});


new WhiteWalker();




