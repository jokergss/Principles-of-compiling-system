@0   lineno:0   Program children: @1 @6 @11 @26 
@1   lineno:0   StmtType:declare           children: @2 @3 
@2   lineno:0   TYPE:int         
@3   lineno:0   Operator:=   children: @4 @5 
@4   lineno:0   VarType:int   VarName:a          
@5   lineno:0   CONST:Interger   value:0     
@6   lineno:1   StmtType:declare           children: @7 @8 
@7   lineno:1   TYPE:int         
@8   lineno:1   Operator:=   children: @9 @10 
@9   lineno:1   VarType:int   VarName:b          
@10  lineno:1   CONST:Interger   value:2     
@11  lineno:2   StmtType:if                children: @12 @16 @21 
@12  lineno:2   Operator:!   children: @13 
@13  lineno:2   Operator:==  children: @14 @15 
@14  lineno:2   CONST:Interger   value:2     
@15  lineno:2   CONST:Interger   value:3     
@16  lineno:3   StmtType:declare           children: @17 @18 
@17  lineno:3   TYPE:int         
@18  lineno:3   Operator:=   children: @19 @20 
@19  lineno:3   VarType:int   VarName:a          
@20  lineno:3   CONST:Interger   value:2     
@21  lineno:4   Operator:=   children: @22 @23 
@22  lineno:4   VarType:int   VarName:a          
@23  lineno:4   Operator:+   children: @24 @25 
@24  lineno:4   VarType:int   VarName:a          
@25  lineno:4   CONST:Interger   value:2     
@26  lineno:6   StmtType:while             children: @27 @30 
@27  lineno:6   Operator:==  children: @28 @29 
@28  lineno:6   VarType:int   VarName:a          
@29  lineno:6   VarType:int   VarName:b          
@30  lineno:7   StmtType:printf            children: @31 
@31  lineno:7   VarType:int   VarName:a          
