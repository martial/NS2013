var Temple_02 = Animation.extend({

    setup: function (s) {

        println("-- Temple_02.js -- ");
        this._super();

        

    },

    update: function (s) {
        
        var angle = depth/6;
        var angle02 = depth/2;
        var angle03 = depth/1.5;
        
        setOrientation(s, 31, 0, 45, angle);
        setOrientation(s, 15, 0, -45, angle);
        
        var pos = getSharpyPos(s, 29);
        lookAt(s, 14, pos.x, pos.y, angle03);
        var pos = getSharpyPos(s, 13);
        lookAt(s, 30, pos.x, pos.y, angle03);
        
        
        setOrientation(s, 29, 0, 45, angle);
        setOrientation(s, 13, 0, -45, angle);
        
        var pos = getSharpyPos(s, 27);
        lookAt(s, 12, pos.x, pos.y, angle02);
        var pos = getSharpyPos(s, 11);
        lookAt(s, 28, pos.x, pos.y, angle02);
        
        
        setOrientation(s, 27, 0, 45, angle);
        setOrientation(s, 11, 0, -45, angle);
        
        var pos = getSharpyPos(s, 25);
        lookAt(s, 10, pos.x, pos.y, 0);
        var pos = getSharpyPos(s, 9);
        lookAt(s, 26, pos.x, pos.y, 0);
        
        
        setOrientation(s, 25, 0, 45, angle);
        setOrientation(s, 9, 0, -45, angle);
        
        var pos = getSharpyPos(s, 23);
        lookAt(s, 8, pos.x, pos.y, angle02);
        var pos = getSharpyPos(s, 7);
        lookAt(s, 24, pos.x, pos.y, angle02);
        
        
        setOrientation(s, 23, 0, 45, angle);
        setOrientation(s, 7, 0, -45, angle);
        
        var pos = getSharpyPos(s, 21);
        lookAt(s, 6, pos.x, pos.y, angle03);
        var pos = getSharpyPos(s, 5);
        lookAt(s, 22, pos.x, pos.y, angle03);
        
        
        setOrientation(s, 21, 0, 45, angle);
        setOrientation(s, 5, 0, -45, angle);
        
        var pos = getSharpyPos(s, 19);
        lookAt(s, 4, pos.x, pos.y, angle03);
        var pos = getSharpyPos(s, 3);
        lookAt(s, 20, pos.x, pos.y, angle03);
        
        
        setOrientation(s, 19, 0, 45, angle);
        setOrientation(s, 3, 0, -45, angle);
        
        var pos = getSharpyPos(s, 17);
        lookAt(s, 2, pos.x, pos.y, angle02);
        var pos = getSharpyPos(s, 1);
        lookAt(s, 18, pos.x, pos.y, angle02);
        
        
        setOrientation(s, 17, 0, 45, angle);
        setOrientation(s, 1, 0, -45, angle);
        
        var pos = getSharpyPos(s, 19);
        lookAt(s, 4, pos.x, pos.y, 0);
        var pos = getSharpyPos(s, 3);
        lookAt(s, 20, pos.x, pos.y, 0);
        
        
        
        
    }



});


new Temple_02();




