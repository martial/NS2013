var JAQUARE = Animation.extend({

    setup: function (s) {

        println("-- JAQUARE.js -- ");
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
            
            setOrientation(s,22, -135, -90, 0);
            setOrientation(s,25, 135, -90, 0);
            setOrientation(s,6, -135, 90, 0); 
            setOrientation(s,9, 135, 90, 0);
          
            setOrientation(s,11, 0, 90, 0);
            setOrientation(s,10, 135, 90, 0);

            
      
            setOrientation(s,27, 0, -90, 0);
            setOrientation(s,26, 135, -90, 0);
            
            setOrientation(s,4,  0, 90, 0);
            
                        setOrientation(s,5, -135, 90, 0);
            
            setOrientation(s,20, 0, -90, 0);
       
            setOrientation(s,21, -135, -90, 0);    
            forceLight(s,7,0);
                                    forceLight(s,8,0);
                                                forceLight(s,23,0);
                  forceLight(s,24,0);


          
        }
});


new JAQUARE();


