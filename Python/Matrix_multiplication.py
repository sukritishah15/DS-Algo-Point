Mat1=[[0,1,2],[3,4,5],[6,7,8]]
Mat2=[[9,7,8],[6,5,4],[3,2,1]]
ResMat=[[0,0,0],[0,0,0],[0,0,0]]
for i in range(len(Mat1)):
    for j in range(len(Mat2[0])):
        for k in range(len(Mat2)):
            ResMat[i][j]+=Mat1[i][k]*Mat2[k][j]
print(ResMat)
