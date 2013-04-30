var Template = Animation.extend({

    setup: function (s) {

        println("-- OHLELEOHLALA.js -- ");
        this._super();



    },

    update: function (s) {


        var time    = of.GetElapsedTimeMillis();

        //var a       = (Math.PI * 2.0) / numSharpy;



            for (var i=0; i<32; i++) {

                var pct      = 0.5 + Math.cos((time)/ (400 ) + speedPct) * 0.5;
                var sinPct   = 0.5 + Math.sin((time) / (400) + speedPct) * 0.5;
                var pan  =  ( 360 * pct);
                var tilt  =  -90 + ( 180 * pct);


                setRotation(s, i, pan, tilt);


            }








    }



});


new Template();




