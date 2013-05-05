var CrossHouse = Animation.extend({

    setup: function (s) {

        println("-- CrossHouse -- ");
        this._super();
        

        


    },

    update: function (s) {
        


        
        lookAt(s, 8, 0, 0, depth / 2);
        lookAt(s, 4, 0, 0, depth / 2);
        lookAt(s, 12, 0, 0, depth / 2);

        lookAt(s, 20, 0, 0, depth / 2);
        lookAt(s, 24, 0, 0, depth / 2);
        lookAt(s, 28, 0, 0, depth / 2);


        var pos     = getSharpyPos(s, 16);
        var posLeft = getSharpyPos(s, 0);
        setOrientation(s, 13, 0, pos.y, 0);
        setOrientation(s, 14, 0, pos.y, 0);
        setOrientation(s, 15, 0, pos.y, 0);

        setOrientation(s, 29, 0, posLeft.y, 0);
        setOrientation(s, 30, 0, posLeft.y, 0);
        setOrientation(s, 31, 0, posLeft.y, 0);

        setOrientation(s, 0, 0, pos.y, 0);
        setOrientation(s, 1, 0, pos.y, 0);
        setOrientation(s, 2, 0, pos.y, 0);

        setOrientation(s, 16, 0, posLeft.y, 0);
        setOrientation(s, 17, 0, posLeft.y, 0);
        setOrientation(s, 18, 0, posLeft.y, 0);

        for ( var i= 0; i<16; i++) {

           // forceLight(s, i, 0);

        }
    


    }
});


new CrossHouse();

