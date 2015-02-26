
import huffman
global code
code={}


def frequency(str):
	frq={}
	for n in str:
		frq[n]=frq.get(n,0)+1
	return frq


def sortls(freq):
	new=[]
	letter=freq.keys()
	for l in letter:
		new.append((freq[l],l))
	new.sort()
	return new


def BuildTree(sorted_list):
	while len(sorted_list) > 1:
		least_two=tuple(sorted_list[0:2])
		reset=sorted_list[2:]
		comb_frq= least_two[0][0] + least_two[1][0]
		sorted_list = reset + [(comb_frq,least_two)]
		sorted_list.sort()
	return sorted_list[0]	


def trimtree(tuples):
	p=tuples[1]
	if type(p) == type(''):
		return p
	else:
		return(trimtree(p[0]),trimtree(p[1]))
		#tuples.sort()
	
	


def assingcodes(node,pat=''):
	global code
	if type(node)==type(""):
		code[node] = pat
	else:
		assingcodes(node[0],pat+"0")
		assingcodes(node[1],pat+"1")

def encode(str):
	list_key=code.keys()
	out=''
	for i in str:
		out += code[i]
	return out


string="aaabccdeeeeeffg"
newlist=sortls(frequency(string))

print frequency(string)
print newlist
print BuildTree(newlist)
trim= BuildTree(newlist)
print trimtree(trim)
node = trimtree(trim)
assingcodes(node)
print code	
print encode("aaabccdeeeeeffg")


