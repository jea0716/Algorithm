import Foundation

func solution(_ s1:[String], _ s2:[String]) -> Int {
    var cnt: Int = 0
    
    for i in s1 {
        for j in s2 {
            if i == j {
                cnt += 1
            }
        }
    }
    
    return cnt
}