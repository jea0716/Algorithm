import Foundation

func solution(_ array:[Int], _ height:Int) -> Int {
    var cnt: Int = 0
    
    for i in array {
        if i > height {
            cnt += 1;
        }
    }
    
    return cnt
}