var Template = Animation.extend({

    setup: function (s) {

        println("-- testr.js -- ");

        this._super();





    },

    update: function (s) {




        for ( var i=0; i<numSharpy; i++) {


            setOrientation(s, i, 0, 0,  -1);
        }



        //lookAt(s, 8, 0,0,-1  );
        //setBrightness   (s, 8,.5);


    }
});




new Template();

