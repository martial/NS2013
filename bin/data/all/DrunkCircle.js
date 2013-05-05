var DrunkCircle = Animation.extend({

    setup: function (s) {

        println("-- DrunkCircle.js -- ");
        this._super();
        this.noise = new SimplexNoise();


    },

    update: function (s) {


       //println(x)


        var time    = of.GetElapsedTimeMillis();
        var pct     = 0.5 + Math.cos(time / 500 + speedPct) * 0.5;
        var radius  = ( height/ 2);
        var a       = (Math.PI * 2.0) / numSharpy;

        var xpct        = this.noise.noiseNormalized(time / 100000, time/10000);
        var ypct        = this.noise.noiseNormalized(time / 10000, time/10000);
        var radiusPct   = this.noise.noiseNormalized(time / 10000, time/10000);

        radius = height / 2 * radiusPct;

        var xPos    = -width + radius / 2 + ( (width - radius / 2) * 2 * xpct);
        var yPos    = -height + radius / 2 + ((height - radius / 2) * 2 * ypct);


        for ( var i=0; i<2; i++) {

            for (var j=0; j<16; j++) {


                var index = i * 16 + j;
                var cnt = ( i == 0 ) ? (16 + index) :  (31 - index);


                x = xPos + Math.cos(cnt * a) * radius;
                y = yPos + Math.sin(cnt * a) * radius;

                lookAt(s, index,   x, y, depth );


            }

        }


    }



});


new DrunkCircle();




