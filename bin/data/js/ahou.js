var Template = Animation.extend({

    setup: function (s) {

        println("-- Template.js -- ");
        this._super();

        for (var i = 0; i < numSharpy; i++) {
            //
        }

    },

    update: function (s) {

        for (var i = 0; i < numSharpy; i++) {

            var index = horizontalSharpies[i];


            var pan = (i % 2 == 0 ) ? 20 : -45;

            //setOrientation  (s, index, pan, 0, 0);
            lookAt          (s, i, 0,0, -300);
            setGobo         (s, i, 0.2);
            setBrightness   (s, i, 1);

             //var fuck = new RandomFuck();
            //fuck.fuck();



        }


    },
    mesCouilles:function () {

        println("mes couilles");

    }
});




new Template();

function mesCouilles() {


    println("mes couilles");

}