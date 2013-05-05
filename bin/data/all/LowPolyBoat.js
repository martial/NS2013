var Template = Animation.extend({

    setup: function (s) {

        println("-- LowPolyBoat.js -- ");
        this._super();



    },

    update: function (s) {

        var time = of.GetElapsedTimeMillis() / 1000;

        var cnt     = 0;
        var cosPct  = 0.0;
        for ( var i=0; i<32; i+=4) {



            var index       = horizontalSharpies[i];
            var nextIndex   = horizontalSharpies[i+1];

            var currentPos  = getSharpyPos(s, i);
            var nextPos     = getSharpyPos(s, i+2);

            //var y = -100 + 200 * speedPct;

            lookAt(s, index, nextPos.x, 0, depth);
            lookAt(s, nextIndex, currentPos.x, 0, depth);


            forceLight(s, horizontalSharpies[i+2], 0)
            forceLight(s, horizontalSharpies[i+3], 0)

            cnt ++;



        }

    }



});


new Template();




