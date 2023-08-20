from rdkit import Chem
from rdkit.Chem import Draw
from rdkit.Chem import AllChem
from rdkit.Chem import rdFMCS
from rdkit.Chem.Descriptors import NumValenceElectrons
from rdkit.Chem import Descriptors

def drawStructure(smis):#绘画结构式
    mols = []#mol形式的列表
    for smi in smis:#枚举smiles类型
        mol = Chem.MolFromSmiles(smi)#把smiles类型转换成mol类型
        mols.append(mol)#转换后添加到mols的列表
    img = Draw.MolsToGridImage(mols, molsPerRow = 4, subImgSize = (500, 500))
    img.show()#图片显示

def elecNum(n):
    while n:
        n -= 1
        smi = str(input())#存储输入分子的smils格式，也就是字符串格式
        mol = Chem.MolFromSmiles(smi)#把smiles类型转换成mol类型
        print("此分子的价电子数为：", Descriptors.NumValenceElectrons(mol))

def stChange(n):
    if n == 1:
        ori = str(input("原结构式："))
        pat = str(input("需要删除的子结构："))
        oriMol = Chem.MolFromSmiles(ori)
        patMol = Chem.MolFromSmarts(pat)
        resMol = AllChem.DeleteSubstructs(oriMol, patMol)#删除子结构，第一个参数是从哪删除，第二个参数是删除的部分·
        mols = [oriMol, resMol]
        img = Draw.MolsToGridImage(mols, molsPerRow = 4, subImgSize=(500,500))
        img.show()
    elif n == 2:
        ori = str(input("原结构式："))
        pat = str(input("需要被取代的子结构："))
        repl = str(input("取代的子结构："))
        oriMol = Chem.MolFromSmiles(ori)
        patMol = Chem.MolFromSmarts(pat)
        repMol = Chem.MolFromSmarts(repl)
        resMol = AllChem.ReplaceSubstructs(oriMol, patMol, repMol)
        mols = [oriMol]
        mols.extend(resMol)
        img = Draw.MolsToGridImage(mols, molsPerRow = 4, subImgSize=(500,500))
        img.show()
    elif n == 3:
        m = int(input("输入分子个数："))
        smis = []
        mols = []
        for i in range(1, m + 1):
            smis.append(str(input()))#smiles类型
            mols.append(Chem.MolFromSmiles(smis[i - 1]))
        res = rdFMCS.FindMCS(mols)#查找上述分子的最大公共子结构，返回值不是mol类型
        common = Chem.MolFromSmarts(res.smartsString)#res.smartsString相当于之前的smiles格式
        mols.append(common)
        img = Draw.MolsToGridImage(mols, molsPerRow = 4, subImgSize=(500,500))
        img.show()
        
if __name__ == '__main__':#入口
    print("1.绘画分子")
    print("2.计算分子的价电子数目")
    print("3.化学转换")
    node = int(input("输入编号以实现上述功能："))#选择的序号
    if node == 1:
        n = int(input("请输入你要绘画的分子数量："))#数量
        smis = []#字符串的列表
        for i in range(n):
            s = str(input())#存储输入分子的smils格式，也就是字符串格式
            smis.append(s)#加入列表
        drawStructure(smis)#调用函数，实际参数为刚刚创建的列表
    elif node == 2:
        n = int(input("请输入你要计算的分子数："))
        elecNum(n)
    else:
        #输出一个目录
        sub = '-' * 3 + 'index'
        print(sub + "\n |---1.删除子结构")
        print(" |---2.取代基替换")
        print(" |---3.最大公共子结构")
        cnt = int(input("输入询问次数："))#cnt存储了你需要询问的次数
        while cnt:
            cnt -= 1
            subnode = int(input("输入编号以实现上述功能："))
            stChange(subnode)#参数为功能序号
