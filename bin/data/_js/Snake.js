var DiscoCubes = Animation.extend({

    setup: function (s) {

        println("-- Snake.js -- ");
        this._super();



    },

    update: function (s) {

        var time = of.GetElapsedTimeMillis();

        for (var i = 0; i < numSharpy; i+=2) {

            var index   = horizontalSharpies[i];
            var indexN   = horizontalSharpies[i+1];

            var x       = -width + i * 100;
            var y       = - height + ( 0.5 + Math.cos( (time + i*100 )/ 800) * .5 ) * height *2;

            lookAt(s, index, x, y, depth);
            lookAt(s, indexN, x, y, depth);

        }


    }



});


new DiscoCubes();




