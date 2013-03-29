var Condor = Animation.extend({

    setup: function (s) {

        println("-- Le condor.js -- ");

        this._super();



    },

    update: function (s) {


        var time        = of.GetElapsedTimeMillis() / (1000 * (1+ ( 1.0 - speedPct)) );
        var maxPan      = 80;

        var anglePct = 1.0 - ( 1.0 - (0.5 + Math.cos((time/2)) * 0.5) ) * 2;

        for (var i = 0; i < leftSharpies.length; i++) {

            //setOrientation  (s, i, 0, 0, 0);
            var index       = leftSharpies[i];
            var brtPct      = (i % 2 == 0) ? 1.0 : 1.0;
            var goboPct     = normalize(i, leftSharpies.length);

            var pan = ( 1.0 - (0.5 + Math.cos((i+time)/4) * 0.5) ) * -maxPan * anglePct;
            setOrientation  (s, index, pan , 0, 0);
            setGobo         (s, index, goboPct);
            setBrightness   (s, index, brtPct);

        }

        for (var i = 0; i < rightSharpies.length; i++) {

            //setOrientation  (s, i, 0, 0, 0);
            var index       = rightSharpies[i];
            var brtPct      = (i % 2 == 0) ? 1.0 : 1.0;
            var goboPct     = normalize(i, rightSharpies.length);

            //println(goboPct);

            //
            var pan = ( 1.0 - (0.5 + Math.cos((i+time)/4) * 0.5) ) * maxPan * anglePct;

            setOrientation  (s, index, pan , 0, 0);
            setGobo         (s, index, goboPct);
            setBrightness   (s, index, brtPct);

        }

    }

});

new Condor();

