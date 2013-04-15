var CosAnimation = Animation.extend({

    setup: function (s) {

        this._super();

        println("-- cos example.js -- ");

        var time = of.GetElapsedTimeMillis();

        for ( var i=0; i<2; i++) {

            for (var j=0; j<16; j++) {

                var index = i * 16 + j;
                //var posSharpy = new fk.Vec3(getPosX(index), getPosY(index), 0);

                //lookAt(s, index,  getMouseX(), 0, -300);
                //setGobo(s, index,  .5);

            }


        }

    },

    update: function (s) {



        var time    = of.GetElapsedTimeMillis();
        var pct     = 0.5 + Math.cos(time / 500 + speedPct) * 0.5;
        var radius  = ( 300 * pct);
        var a       = (Math.PI * 2.0) / numSharpy;


        for ( var i=0; i<2; i++) {

            for (var j=0; j<16; j++) {


                var index = i * 16 + j;
                var cnt = ( i == 0 ) ? (16 + index) :  (31 - index);
                var yo = 0.5 + Math.cos( (time + index * 14 ) / 50 * speedPct) * 0.5;



                x = Math.cos(cnt * a) * radius;
                y = Math.sin(cnt * a) * radius;

                lookAt(s, index,   x, y, -300 );
                setGobo(s, cnt,  1);
                setBrightness(s, cnt, yo);

            }

        }

    }


});

new CosAnimation();

