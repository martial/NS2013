var NoiseExample = Animation.extend({


    setup: function (s) {

        println("-- Noise example.js -- ");
        this._super();
        this.noise = new SimplexNoise();


    },

    update: function (s) {

        for (var i = 0; i < numSharpy; i++) {


            var pct     = this.noise.noiseNormalized(timeMillis / 1000 + speedPct, i);

            //var angle   = -45 + ( 90 * pct);
            //setOrientation  (s, i, angle,0, 0);

            setOrientation  (s, i, 0,0, 0);
            setGobo         (s, i, pct);
            setBrightness   (s, i, pct);

        }


    }

});

new NoiseExample();


