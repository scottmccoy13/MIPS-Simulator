# MIPS-Simulator
The purpose of this project is to simulate the execution of a MIPS assembly language
program given in binary format.


The formatting of the different types of instructions are given by the following table.

<table class="wikitable">
<tbody><tr>
<th>Type</th>
<th colspan="6">-31- &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; format (bits) &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; -0-</th>
</tr>
<tr align="center">
<td><b>R</b></td>
<td>opcode (6)</td>
<td>rs (5)</td>
<td>rt (5)</td>
<td>rd (5)</td>
<td>shamt (5)</td>
<td>funct (6)</td>
</tr>
<tr align="center">
<td><b>I</b></td>
<td>opcode (6)</td>
<td>rs (5)</td>
<td>rt (5)</td>
<td colspan="3">immediate (16)</td>
</tr>
<tr align="center">
<td><b>J</b></td>
<td>opcode (6)</td>
<td colspan="5">address (26)</td>
</tr>
</tbody></table>

Additional reference information:
http://www.mrc.uidaho.edu/mrc/people/jff/digital/MIPSir.html

https://en.wikipedia.org/wiki/MIPS_architecture
