var NS = Animation.extend({

    setup: function (s) {

        println("-- NS.js -- ");
        this._super();

        

    },

    update: function (s) {
        
        //N
        setOrientation(s, 31, 0, 0, 0);
        setOrientation(s, 16, 0, 0, 0);
        
        var pos = getSharpyPos(s, 30);
        lookAt(s, 17, pos.x, pos.y, depth);
        
        
        
        setOrientation(s, 31, 0, 0, 0);
        setOrientation(s, 16, 0, 0, 0);
        
        var pos = getSharpyPos(s, 1);
        lookAt(s, 14, pos.x, pos.y, depth);

        //S
        setOrientation(s, 12, 45, 45, 0);
        setOrientation(s, 28, 45, -45, 0);
        setOrientation(s, 11, 45, 45, 0);
        setOrientation(s, 27, 45, -45, 0);
        
        setOrientation(s, 19, -45, -45, 0);
        setOrientation(s, 3, -45, 45, 0);
        setOrientation(s, 20, -45, -45, 0);
        setOrientation(s, 4, -45, 45, 0);
        
        var pos = getSharpyPos(s, 26);
        lookAt(s, 5, pos.x, pos.y, 0);
        
        var pos = getSharpyPos(s, 4);
        lookAt(s, 25, pos.x, pos.y, 0);
        
        var pos = getSharpyPos(s, 27);
        lookAt(s, 6, pos.x, pos.y, 0);
        
        forceLight(s, 13, 0);
        forceLight(s, 10, 0);
        forceLight(s, 9, 0);
        forceLight(s, 8, 0);
        forceLight(s, 7, 0);
        forceLight(s, 2, 0);
        forceLight(s, 1, 0);
        
        forceLight(s, 30, 0);
        forceLight(s, 29, 0);
        forceLight(s, 26, 0);
        forceLight(s, 24, 0);
        forceLight(s, 23, 0);
        forceLight(s, 22, 0);
        forceLight(s, 21, 0);
        forceLight(s, 18, 0);
        
    }



});


new NS();




