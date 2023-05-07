class SeatManager {
private:
    int n;
    set<int> availableSeats;
public:
    SeatManager(int n) {
        this->n = n;
        for(int i = 1; i <= n; i++) {
            availableSeats.insert(i);
        }
    }
    
    int reserve() {
        int seatNumber = *availableSeats.begin();
        availableSeats.erase(seatNumber);
        return seatNumber;
    }
    
    void unreserve(int seatNumber) {
        availableSeats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */