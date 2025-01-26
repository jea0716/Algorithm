import Foundation

func solution(_ n:Int) -> Int {
    guard n > 0 else { return 0 }
    
    var sum: Int = 0;
    
    for i in 1...Int(sqrt(Double(n))) {
        if n % i == 0 {
            sum += i
            if i != n / i {
                sum += n / i
            }
        }
    }
    
    return sum
}