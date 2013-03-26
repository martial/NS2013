// ----------------------------
function versatubesTypo()
{
	this.lettersDef = {};
	this.lettersGeom = {}; 
	this.lettersEdge = []; // TODO ?


	// ----------------------------------------
	this.lettersEdge = [];

	// ----------------------------------------
	this.lettersDef['0'] = {w:1, a:[ [2,0, 3,0], [2,0, 1,1], [3,0, 2,1], /*[1,1, 2,1],*/ [1,1, 0,2], [2,1, 1,2], [0,2, 1,2] ]};
	this.lettersDef['1'] = {w:1, a:[ [3,0, 1,2] ]};
	this.lettersDef['2'] = {w:1, a:[ [2,0, 3,0], [3,0, 2,1], [2,1, 1,1], [1,1, 0,2], [0,2, 1,2] ]};
	this.lettersDef['3'] = {w:1, a:[ [2,0, 3,0], [3,0, 2,1], [2,1, 1,1], [2,1, 1,2], [0,2, 1,2] ]};
	this.lettersDef['4'] = {w:1, a:[ [2,0, 1,1], [1,1, 2,1], [3,0, 1,2] ]};
	this.lettersDef['5'] = {w:1, a:[ [2,0, 3,0], [2,0, 1,1], [2,1, 1,1], [2,1, 1,2], [0,2, 1,2] ]};
	this.lettersDef['6'] = {w:1, a:[ [2,0, 1,1], [2,1, 1,1], [2,1, 1,2], [0,2, 1,2], [0,2, 1,2], [0,2, 1,1] ]};
	this.lettersDef['7'] = {w:1, a:[ [2,0, 3,0], [3,0, 1,2] ]};
	this.lettersDef['8'] = {w:1, a:[ [2,0, 3,0], [2,0, 1,1], [3,0, 2,1], [1,1, 2,1], [1,1, 0,2], [2,1, 1,2], [0,2, 1,2] ]};
	this.lettersDef['9'] = {w:1, a:[ [2,0, 3,0], [2,0, 1,1], [3,0, 2,1], [1,1, 2,1], /*[1,1, 0,2],*/ [2,1, 1,2], [0,2, 1,2] ]};
	this.lettersDef['_'] = {w:1, a:[ [0,3, -1,3] ]};
	this.lettersDef[' '] = {w:1, a:[]};


	for (var c in this.lettersDef)
	{
		var letterDef = this.lettersDef[c];
		this.lettersGeom[c] = {w:0,lines:[]};
		this.lettersGeom[c].w = letterDef.w;
		for (j=0;j<letterDef.a.length;j++){
			this.lettersGeom[c].lines.push( new Line(letterDef.a[j]) );
		}
	}
}
// ----------------------------
typo = new versatubesTypo();


// ----------------------------
function versatubesString()
{
	
	this.set = function(s)
	{
		this.lettersGeom = [];
		for (i=0;i<s.length;i++){
			this.lettersGeom.push( typo.lettersGeom[s.charAt(i)] ); 
		}
	}

	this.displayLetter = function(letter, i,j)
	{
		var p = versatubes.getPoint(i-2,j); // -2 for the offset of the letter definition
		of.PushMatrix();
		of.Translate(p.x,p.y,0);
			for (i=0;i<letter.lines.length;i++)
				letter.lines[i].display();
		of.PopMatrix();

	}

	this.display = function(i,j)
	{
		var x=i;
		for (i=0;i<this.lettersGeom.length;i++){
			this.displayLetter(this.lettersGeom[i],x,0);
			x+=this.lettersGeom[i].w; // width of the char
		}
	}
	
	this.width = function()
	{
		var w=0;
		for (i=0;i<this.lettersGeom.length;i++){
			w+=this.lettersGeom[i].w;
		}
		return w;
	}
	
}

