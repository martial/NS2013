var CrazyRoof = Animation.extend({

    setup: function (s) {

        println("-- Vertical Scan.js -- ");

        this._super();

    },

    update: function (s) {

        var time = of.GetElapsedTimeMillis();


        for (var i = 0; i < leftSharpies.length; i++) {

            var x = -width  + ( 0.5 + Math.cos((time + i * 100 ) / 1200) * .5 ) * width * 2;
            //x-= i*20;
            lookAt(s, i, x, -250, 0);

        }

        for (var i = 0; i < rightSharpies.length; i++) {

            var x = -width  + ( 0.5 + Math.cos((time + i * 100 ) / 1200) * .5 ) * width * 2;
            //x-= i*20;
            lookAt(s, rightSharpies[i], x, 250, 0);

        }

    }



});


new CrazyRoof();




