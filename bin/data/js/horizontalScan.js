var Horizontal = Animation.extend({

    setup: function (s) {

        println("-- Horizontal.js -- ");

        this._super();



    },

    update: function (s) {

        var time        = of.GetElapsedTimeMillis() / (30 * (1+ ( 1.0 - speedPct)) );
        var maxPan      = 80;

        for (var i = 0; i < horizontalSharpies.length; i++) {

            //setOrientation  (s, i, 0, 0, 0);
            var index       = horizontalSharpies[i];
            var brtPct      = (i % 2 == 0) ? 1.0 : 1.0;
            var goboPct     = normalize(i, leftSharpies.length);

            var cosTime     = (i % 2 == 0) ? i : i- 1;
            var pct         = ( 1.0 - (0.5 + Math.cos((cosTime+time)/10) * 0.5) );
            pct             = Math.round(pct);

            var pan         = ( i < 8 || i > 24) ? 0 : (i % 2 == 0) ? - 80 : 80;

            setOrientation  (s, index, pan , 0, 0);
            setGobo         (s, index, pct);
            setBrightness   (s, index, brtPct);

        }


    }

});

new Horizontal();

