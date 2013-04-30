var Ascension = Animation.extend({

    setup: function (s) {

        println("-- Ascension.js -- ");
        this._super();



    },

    update: function (s) {



        var time = of.GetElapsedTimeMillis() / 1000;



        for ( var i=0; i<32; i+=2) {


            var pct = 0.5 + Math.cos(time + i/10) * 0.5;
            var index           = horizontalSharpies[i];
            var nextIndex       = horizontalSharpies[i+1];

            var currentPos      = getSharpyPos(s, index);
            var nextPos         = getSharpyPos(s, index);



            lookAt(s, index, nextPos.x, 0, depth * pct);
            lookAt(s, nextIndex, currentPos.x, 0, depth * pct);

        }

       // var pos     = getSharpyPos(s, 31);
        //lookAt(s, 14, pos.x, 0, depth);





    }



});


new Ascension();




