import Foundation

func solution(_ n:Int, _ k:Int) -> Int {
    return (n * 12000) + ((k - (n / 10)) * 2000)  
}