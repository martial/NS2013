var OpenArms = Animation.extend({

    setup: function (s) {

        println("-- OpenArms.js -- ");
        this._super();



    },

    update: function (s) {

        var time = of.GetElapsedTimeMillis() / 1000;

        for ( var i=0; i<32; i+=4) {

            var step = Math.floor(16 * i / 32 );

            var pct = 0.5 + Math.cos(time + step/10) * 0.5;


            var index    = horizontalSharpies[i];
            var index2   = horizontalSharpies[i+1];
            var index3   = horizontalSharpies[i+2];
            var index4   = horizontalSharpies[i+3];

            var tilt     = -90 + 180 * pct;


            var pan = 180;

            setRotation(s, index, pan, tilt );
            setRotation(s, index3, pan, tilt );

            setRotation(s, index2, pan, -tilt );
            setRotation(s, index4, pan, -tilt );






        }

    }



});


new OpenArms();




