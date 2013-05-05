var Zob_02 = Animation.extend({

    setup: function (s) {

        println("-- Zob_02.js -- ");
        this._super();

        

    },

    update: function (s) {
        
        var angle_1 = depth/2;
        var angle_2 = depth/4;
        var angle_3 = depth/6;
        var angle_4 = depth/8;
        
        //
        setOrientation(s, 31, 0, 45, angle_1);
        setOrientation(s, 15, 0, -45, angle_1);
        
        setOrientation(s, 30, 0, 45, angle_2);
        setOrientation(s, 14, 0, -45, angle_2);
        
        setOrientation(s, 29, 0, 45, angle_3);
        setOrientation(s, 13, 0, -45, angle_3);
        
        setOrientation(s, 28, 0, 45, angle_4);
        setOrientation(s, 12, 0, -45, angle_4);
        
        //
        setOrientation(s, 27, 0, -45, angle_1);
        setOrientation(s, 11, 0, 45, angle_1);
        
        setOrientation(s, 26, 0, -45, angle_2);
        setOrientation(s, 10, 0, 45, angle_2);
        
        setOrientation(s, 25, 0, -45, angle_3);
        setOrientation(s, 9, 0, 45, angle_3);
        
        setOrientation(s, 24, 0, -45, angle_4);
        setOrientation(s, 8, 0, 45, angle_4);
        
        //
        setOrientation(s, 23, 0, 45, angle_1);
        setOrientation(s, 7, 0, -45, angle_1);
        
        setOrientation(s, 22, 0, 45, angle_2);
        setOrientation(s, 6, 0, -45, angle_2);
        
        setOrientation(s, 21, 0, 45, angle_3);
        setOrientation(s, 5, 0, -45, angle_3);
        
        setOrientation(s, 20, 0, 45, angle_4);
        setOrientation(s, 4, 0, -45, angle_4);
        
        //
        setOrientation(s, 19, 0, -45, angle_1);
        setOrientation(s, 3, 0, 45, angle_1);
        
        setOrientation(s, 18, 0, -45, angle_2);
        setOrientation(s, 2, 0, 45, angle_2);
        
        setOrientation(s, 17, 0, -45, angle_3);
        setOrientation(s, 1, 0, 45, angle_3);
        
        setOrientation(s, 16, 0, -45, angle_4);
        setOrientation(s, 0, 0, 45, angle_4);
        
    }



});


new Zob_02();




