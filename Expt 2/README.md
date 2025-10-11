# Experiment 2: Disk Scheduling Algorithms

AIM - Implement the Disk Scheduling Alogirthms

---

## 1. FCFS (First-Come, First-Served) Disk Scheduling

**Code:** [FCFS Program](https://github.com/iamkarthik2004/S5-SSMP-LAB-KTU-2025/blob/main/Expt%202/FCFS_disk.c)  

**Sample Output:**

```
Enter Head position: 50

Enter the number of disk requests: 8
Enter the disk requests: 
48 98 153 37 122 14 124 66

****FCFS DISK SCHEDULING ALGORITHM*****
Head movement from 50 to 48:2
Head movement from 48 to 98:50
Head movement from 98 to 153:55
Head movement from 153 to 37:116
Head movement from 37 to 122:85
Head movement from 122 to 14:108
Head movement from 14 to 124:110
Head movement from 124 to 66:58
Total Seektime is: 584
```

## 2. SCAN DISK SCHEDULING

**Code:** [SCAN DISK Program](https://github.com/iamkarthik2004/S5-SSMP-LAB-KTU-2025/blob/main/Expt%202/SCAN.c)  

**Sample Output:**

```
Enter Head position: 100
Enter number of disk requests: 6
Enter the disk size: 200
Enter the disk requests: 20 89 130 45 120 180

	SCAN DISK SCHEDULING

Head movement from 100 to 120 : 20
Head movement from 120 to 130 : 10
Head movement from 130 to 180 : 50
Head movement from 180 to 199 : 19
Head movement from 199 to 89 : 110
Head movement from 89 to 45 : 44
Head movement from 45 to 20 : 25

Total seek time is : 278
```

## 3. C - SCAN DISK SCHEDULING

**Code:** [C - SCAN DISK Program](https://github.com/iamkarthik2004/S5-SSMP-LAB-KTU-2025/blob/main/Expt%202/C-SCAN.c)  

**Sample Output:**

```

```
