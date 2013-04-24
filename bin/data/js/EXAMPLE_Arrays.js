var Template = Animation.extend({

    setup: function (s) {

        println("-- Example arrays.js -- ");
        this._super();

    },

    update: function (s) {



        for (var i = 0; i < numSharpy; i++) {

            // horizontalSharpies nous renvoie l'index des sharpies, mais mappé à l'envers

            var index = horizontalSharpies[i];
            var angle = ( i< 16) ?  100 : -100;

            // afin de mieux comprendre, remplacer index par i

            setOrientation(s,index,0, angle, depth / 2);


            
        }


        //setBrightness(s, 15, 1);



        /*

        Ici un autre example avec left et right sharpies


        for (var i = 0; i < leftSharpies.length; i++) {

         setOrientation(s, leftSharpies[i], 0, 100, depth / 2);

        }

        for (var i = 0; i < rightSharpies.length; i++) {

         setOrientation(s, rightSharpies[i], 0, -100, depth / 2);

        }


        */





    }
});


new Template();


