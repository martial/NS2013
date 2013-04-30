var DiscoCircle = Animation.extend({

    setup: function (s) {

        println("-- Disco Circle.js -- ");

        this._super();



    },

    update: function (s) {


        var time    = of.GetElapsedTimeMillis();
        var pct     = 0.5 + Math.cos(time / 500 + speedPct) * 0.5;
        var radius  = ( height * pct);
        var a       = (Math.PI * 2.0) / numSharpy;


        for ( var i=0; i<2; i++) {

            for (var j=0; j<16; j++) {


                var index = i * 16 + j;
                var cnt = ( i == 0 ) ? (16 + index) :  (31 - index);


                x = Math.cos(cnt * a) * radius;
                y = Math.sin(cnt * a) * radius;

                lookAt(s, index,   x, y, depth );


            }

        }

    }



});


new DiscoCircle();




