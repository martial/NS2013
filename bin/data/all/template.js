var Template = Animation.extend({

    setup: function (s) {

        println("-- CrossHouse.js -- ");
        this._super();



    },

    update: function (s) {


        var time    = of.GetElapsedTimeMillis();
        var radius  = (height *10 * speedPct);
        var a       = (Math.PI * 2.0) / numSharpy;


        for ( var i=0; i<2; i++) {

            for (var j=0; j<16; j++) {


                var index = i * 16 + j;
                var cnt = ( i == 0 ) ? (16 + index) :  (31 - index);


                x = Math.cos(cnt * a) * radius;
                y = Math.sin(cnt * a) * radius;

                lookAt(s, index,   x, y, depth * speedPct);


            }


        }


        lookAt(s, 4,   0, 0, depth/2 );
        lookAt(s, 7,   0, 0, depth );
        lookAt(s, 8,   0, 0, depth );
        lookAt(s, 11,   0, 0, depth /2);

        lookAt(s, 20,   0, 0, depth/2 );
        lookAt(s, 23,   0, 0, depth );
        lookAt(s, 24,   0, 0, depth );
        lookAt(s, 27,   0, 0, depth /2);


    }



});


new Template();




