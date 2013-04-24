var ExampleOrientation = Animation.extend({

    setup: function (s) {

        println("-- Example Orientation.js -- ");
        this._super();




    },


    update: function (s) {


        //setOrientation(s, 8, 45, 45, -20);


        // setOrientation et la meme chose que lookAt
        // sauf que le point d'origine est la position du sharpy !

        for (var i = 0; i < numSharpy; i++) {

            var y = ( i % 2 == 0 ) ? -45 : 45;

            setOrientation(s, i, 45,y, -12);

            
        }

    }
});


new ExampleOrientation();


