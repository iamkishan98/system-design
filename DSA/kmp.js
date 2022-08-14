// String matching Algorithm (KMP)
class KMP
{
    constructor(){

    }

    prefixFun(str, len){
        let prefixArray = new Array(len)
        prefixArray[0] = 0

        for(let i=1; i< len; i++){
            let j = prefixArray[i-1]

            while(j>0 && str[i] != str[j]){
                j = prefixArray[j-1]
            }

            if(str[i] == str[j])
                j += 1
            prefixArray[i] = j
        }

        return prefixArray
    }

    stringMatch(og, sub){

        let len = sub.length
        let prefixArray = new Array(len)
        prefixArray = this.prefixFun(sub, len)
        console.log(prefixArray)
        
        // Try to match the substring from a given original string
        // Maintain two objects i for og ,j for sub
        let j = 0
        let i = 0
        let startIndex = -1
        while(i < og.length)
        {
            // If characters are same
            if(og[i] == sub[j]){
                i += 1
                j += 1
            }
            else{
                // If we have matched any characters before then
                if(j != 0){
                    j = prefixArray[j-1]
                }
                else{
                    i += 1
                }
            }

            // If all characters matched
            if(j == len){
                startIndex = i - len
                break
            }

        }

        return startIndex


    }


}

const kmp = new KMP()
const ans = kmp.stringMatch("bcaabcdaabaabcd", "aabcdaab")
console.log(ans)