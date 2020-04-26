# 花札シミュレータ

花札のゲームMatgoの終盤の分析に使ったシミュレータです。  
accurate_versionはお互いの手がお互いに見えてないことに忠実にシミュレートするヴァージョンです。後攻8巡目、先攻9巡目、後攻9巡目の分析にはこちらを用いました。    
rough_versionは次の一手だけ相手の手が見えないことを前提にした計算を行い、それよりも後はお互いの手が見えている状態でのシミュレートをします。そのため概算となりますが、求まるのが速いため先攻8巡目、後攻7巡目の分析にはこちらを用いました。  

# 使い方
makeしてください。  

test.txtに横4×縦23の行列で局面を指定してください。  
指定方法の例はex5.txtをご覧ください。  
  
accurate_versionならmajime3main.exeを、rough_versionならmajigaba1main.exeを実行してください。
  
0を入力すると期待値を計算します。

