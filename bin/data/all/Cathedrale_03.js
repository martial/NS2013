var Cathedrale_03 = Animation.extend({

    setup: function (s) {

        println("-- Cathedrale_03.js -- ");
        this._super();

        

    },

    update: function (s) {
        
        //roof part 01
        setOrientation(s, 0, 45, 45, -15);
        setOrientation(s, 16, 45, -45, -15);
        
        //roof part 02
        setOrientation(s, 20, 45, -45, -10);
        setOrientation(s, 4, 45, 45, -10);
        
        //roof part 03
        setOrientation(s, 24, 45, -45, -5);
        setOrientation(s, 8, 45, 45, -5);
        
        //roof part 04
        setOrientation(s, 28, 45, -45, -0);
        setOrientation(s, 12, 45, 45, -0);
        
        //wall right
        setOrientation(s, 17, 0, 1, 0);
        setOrientation(s, 19, 0, -1, 0);
        setOrientation(s, 21, 0, 1, 0);
        setOrientation(s, 23, 0, -1, 0);
        setOrientation(s, 25, 0, 1, 0);
        setOrientation(s, 27, 0, -1, 0);
        setOrientation(s, 29, 0, 1, 0);
        setOrientation(s, 31, 0, -1, 0);
        
        //wall right
        setOrientation(s, 1, 0, 1, 0);
        setOrientation(s, 3, 0, -1, 0);
        setOrientation(s, 5, 0, 1, 0);
        setOrientation(s, 7, 0, -1, 0);
        setOrientation(s, 9, 0, 1, 0);
        setOrientation(s, 11, 0, -1, 0);
        setOrientation(s, 13, 0, 1, 0);
        setOrientation(s, 15, 0, -1, 0);
    
        
        //forceLight(s, i, 0);


    }



});


new Cathedrale_03();




