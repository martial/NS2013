var Template = Animation.extend({

    setup: function (s) {

        println("-- yo.js -- ");
        this._super();

        for (var i = 0; i < numSharpy; i++) {
            //
        }

    },

    update: function (s) {

        var angle = 45;
        setOrientation  (s, 0, 0, 0, 0);
        setOrientation  (s, 8, 0, 45, 0);
        setOrientation  (s, 15, 45, 0, 0);

        setOrientation  (s, 23, 45, 45, 0);


        setBrightness   (s, 8, 1);

        /*
        for (var i = 0; i < numSharpy; i++) {

            var index = horizontalSharpies[i];


            var pan = (i % 2 == 0 ) ? 20 : -45;

            setOrientation  (s, i, 0, 0, 0);
            //lookAt          (s, i, 0,0, -300);
            setGobo         (s, i, 1);
            setBrightness   (s, i, 1);

             //var fuck = new RandomFuck();
            //fuck.fuck();



        }

        */


    },
    mesCouilles:function () {

        println("mes couilles");

    }
});




new Template();

function mesCouilles() {


    println("mes couilles");

}