var TRIGO = Animation.extend({

    setup: function (s) {

        println("-- TRIGO.js -- ");
        this._super();

    },

    update: function (s) {
    
    
            setOrientation(s, 0, -135,90, 0);
            setOrientation(s, 16, -135,-90, 0);
            setOrientation(s, 1, -135,90, 0);
            setOrientation(s, 17, -135,-90, 0);
        
            setOrientation(s, 2, 135,90, 0);
            setOrientation(s, 18, 135,-90, 0);
            setOrientation(s, 3, 135,90, 0);
            setOrientation(s, 19, 135,-90, 0);  
            
            
            setOrientation(s, 12, -135,90, 0);
            setOrientation(s, 28, -135,-90, 0);
            setOrientation(s, 13, -135,90, 0);
            setOrientation(s, 29, -135,-90, 0);
        
            setOrientation(s, 14, 135,90, 0);
            setOrientation(s, 30, 135,-90, 0);
            setOrientation(s, 15, 135,90, 0);
            setOrientation(s, 31, 135,-90, 0);
            
            lookAt(s,22, 0, 0, depth);
            lookAt(s,25, 0, 0, depth);
            lookAt(s,6, 0, 0, depth); 
            lookAt(s,9, 0, 0, depth);
            lookAt(s,8, 375, -150, depth);
            lookAt(s,11, 375, -150, depth);
                        lookAt(s,10, 375, -150, depth);

            
            lookAt(s,24, 375, 150, depth);
            lookAt(s,27, 375, 150, depth);
            			lookAt(s,26, 375, 150, depth);
            
            lookAt(s,4, -375, -150, depth);
            lookAt(s,7, -375, -150, depth);
                        lookAt(s,5, -375, -150, depth);
            
            lookAt(s,20, -375, 150, depth);
            lookAt(s,23, -375, 150, depth);
                        lookAt(s,21, -375, 150, depth);                          
        }
});


new TRIGO();


