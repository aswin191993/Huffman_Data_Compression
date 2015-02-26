codes = {}
str="aaabccdeeeeeffg"

function frequency(string){
	dict=[]
	var count=1;
	for(var i=0;i<(string.length);i++){
		if(string[i]==string[i+1]){
			count++;
		}
		else{
			dict.push([count,string[i]]);
			count=1;
		}
	}
	dict.sort();
	console.log(dict);
	return dict;
}

function buildTree(tuples) {

        while(tuples.length > 1) {

                var leastTwo = [tuples[0][1], tuples[1][1]];
                var theRest  = tuples.slice(2,tuples.length);                    
                var combFreq = tuples[0][0] + tuples[1][0];
                tuples   = theRest;
                sample = [combFreq, leastTwo];
                tuples.push(sample);
                tuples.sort();
        }
     return tuples;
}

function trimTree(tuples) {
        return tuples[0][1];
}

function assignCodes (node, pat) {
     pat = pat || "";
     if (typeof node == typeof "") {
         codes[node] = pat;
     }
     else {
         assignCodes(node[0], pat+"0");
         assignCodes(node[1], pat+"1");
     }
}

tree= trimTree(buildTree(frequency(str)));
assignCodes(tree);
console.log(codes);

function encode (str) {
        var output = "";
        for (var ch in str) {
                 output = output + codes[str[ch]];
        }
return output;
}
op=encode(str);
console.log(op);
function decode(tree,str) {
        var output = "";
        p = tree
        for (var bit in str) {
                if (str[bit] == '0') {
                        p = p[0];
                }
                else          {
                        p = p[1];
                }
                if (typeof(p) == typeof("")) {
                        output = (output + p) ;
                         p = tree  ;
                }
        }
        return output;
}
console.log(decode(tree,encode(str)));

