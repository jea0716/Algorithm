import Foundation

func solution(_ n:Int) -> Int {
    var check: Bool = false
    var answer: Int = 1;
    
    while !check {
        if n % answer == 1 {
            check = true
        } else {
            answer += 1
        }
    }
    
    return answer
}