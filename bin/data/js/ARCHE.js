var ARCHE = Animation.extend({

    setup: function (s) {

        println("-- ARCHE.js -- ");
        this._super();

    },

    update: function (s) {


        // setOrientation et la meme chose que lookAt
        // sauf que le point d'origine est la position du sharpy !

        for (var i = 0; i < numSharpy; i++) {

	        var y =0;
            //var y = ( i % 2 == 0 ) ? -45 : 45;
            
            //ligne gauche
            
            setOrientation(s, 0, 0, y, 0);
            setOrientation(s, 1, 150,y, depth);
            setOrientation(s, 2, 0,640, depth);
            setOrientation(s, 3, -150,y, depth);
            setOrientation(s, 4, 0,y, depth);
            setOrientation(s, 5, 150,y, depth);
            setOrientation(s, 6, 0,640, depth);
            setOrientation(s, 7, -150,y, depth);
            setOrientation(s, 8, 0,y, depth);
            setOrientation(s, 9, 150,y, depth);
            setOrientation(s, 10, 0,640, depth);
            setOrientation(s, 11, -150,y, depth);
            setOrientation(s, 12, 0,y, depth);
            setOrientation(s, 13, 150,y, depth);
            setOrientation(s, 14, 0,640, depth);
            setOrientation(s, 15, -150,y, depth);
            //ligne droite

            setOrientation(s, 16, 0,y, 0);
            setOrientation(s, 17, 150,y, depth);
            setOrientation(s, 18, 0,-640, depth);
            setOrientation(s, 19, -150,y, depth);
            setOrientation(s, 20, 0,y, depth);
            setOrientation(s, 21, 150,y, depth);
            setOrientation(s, 22, 0,-640, depth);
            setOrientation(s, 23, -150,y, depth);
            setOrientation(s, 24, 0,y, depth);
            setOrientation(s, 25, 150,y, depth);
            setOrientation(s, 26, 0,-640, depth);
            setOrientation(s, 27, -150,y, depth);
            setOrientation(s, 28, 0,y, depth);
            setOrientation(s, 29, 150,y, depth);
            setOrientation(s, 30, 0,-640, depth);
            setOrientation(s, 31, -150,y, depth);
            
            
        }

    }
});


new ARCHE();


