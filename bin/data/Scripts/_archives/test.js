this.angle = 0;

//--------------------------------------------------------------
function setup()
{
}

//--------------------------------------------------------------
function draw(w,h)
{
    // TEST : modifier la valeur 300 et sauver le fichier
    // En mode live coding, la modification est immédiatement répercutée
    // Sur le dessin du masque
/*    var amplitude = 300.0;


	var d = amplitude*0.5*(1+Math.cos(Math.PI/180*angle));

	of.SetColor(255,255,255);
	of.Ellipse(w/2,h/2,d,d);
*/
	of.SetColor(255,255,255);
	of.Ellipse(60*6,0,5,5);

}

//--------------------------------------------------------------
function update(dt)
{
	this.angle += 2.1;
}
