var CrazyRoof = Animation.extend({

    setup: function (s) {

        println("-- Vertical Scan.js -- ");

        this._super();

    },

    update: function (s) {

        var time = of.GetElapsedTimeMillis();

        var tilt       = - 90 + ( 0.5 + Math.cos( (time )/ 300 * speedPct) * .5 ) * 180;

        for (var i = 0; i < numSharpy; i++) {
            setRotation(s, i, 90, tilt);
        }
    }



});


new CrazyRoof();




