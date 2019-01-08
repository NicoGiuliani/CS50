<div id="content">
                <h1>Caesar</h1>
<div class="sect1">
<div class="sectionbody">
<div class="paragraph">
<p>Implement a program that encrypts messages using Caesar’s cipher, per the below.</p>
</div>
<div class="listingblock">
<div class="content">
<pre class="pygments highlight"><code>$ <span class="underline">./caesar 13</span>
plaintext:  <span class="underline">HELLO</span>
ciphertext: URYYB</code></pre>
</div>
</div>
</div>
</div>
<div class="sect1">
<h2 id="background"><a class="link" href="#background">Background</a></h2>
<div class="sectionbody">
<div class="paragraph">
<p>Supposedly, Caesar (yes, that Caesar) used to "encrypt" (i.e., conceal in a reversible way) confidential messages by shifting each letter therein by some number of places. For instance, he might write A as B, B as C, C as D, …​, and, wrapping around alphabetically, Z as A.  And so, to say HELLO to someone, Caesar might write IFMMP. Upon receiving such messages from Caesar, recipients would have to "decrypt" them by shifting letters in the opposite direction by the same number of places.</p>
</div>
<div class="paragraph">
<p>The secrecy of this "cryptosystem" relied on only Caesar and the recipients knowing a secret, the number of places by which Caesar had shifted his letters (e.g., 1). Not particularly secure by modern standards, but, hey, if you’re perhaps the first in the world to do it, pretty secure!</p>
</div>
<div class="paragraph">
<p>Unencrypted text is generally called <em>plaintext</em>. Encrypted text is generally called <em>ciphertext</em>. And the secret used is called a <em>key</em>.</p>
</div>
<table class="tableblock frame-all grid-all stretch">
<caption class="title">Table 1. Encrypting HELLO with a key of 1 yields IFMMP.</caption>
<colgroup>
<col style="width: 16.6666%;">
<col style="width: 16.6666%;">
<col style="width: 16.6666%;">
<col style="width: 16.6666%;">
<col style="width: 16.6666%;">
<col style="width: 16.667%;">
</colgroup>
<tbody>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock"><strong>plaintext</strong></p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">H</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">E</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">L</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">L</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">O</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock"><strong>+ key</strong></p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">1</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">1</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">1</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">1</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">1</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock"><strong>= ciphertext</strong></p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">I</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">F</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">M</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">M</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">P</p></td>
</tr>
</tbody>
</table>
<div class="paragraph">
<p>More generally, Caesar’s algorithm (i.e., cipher) encrypts messages by "rotating" each letter by <em>k</em> positions. More formally, if <em>p</em> is some plaintext (i.e., an unencrypted message), <em>p<sub>i</sub></em> is the <em>i<sup>th</sup></em> character in <em>p</em>, and <em>k</em> is a secret key (i.e., a non-negative integer), then each letter, <em>c<sub>i</sub></em>, in the ciphertext, <em>c</em>, is computed as</p>
</div>
<div class="stemblock">
<div class="content">
<span class="MathJax_Preview" style="display: none;"></span><span class="mjx-chtml MJXc-display" style="text-align: center;"><span id="MathJax-Element-1-Frame" class="mjx-chtml MathJax_CHTML" tabindex="0" style="font-size: 117%; text-align: center;"><span id="MJXc-Node-1" class="mjx-math"><span id="MJXc-Node-2" class="mjx-mrow"><span id="MJXc-Node-3" class="mjx-msubsup"><span class="mjx-base"><span id="MJXc-Node-4" class="mjx-mi"><span class="mjx-char MJXc-TeX-math-I" style="padding-top: 0.216em; padding-bottom: 0.27em;">c</span></span></span><span class="mjx-sub" style="font-size: 70.7%; vertical-align: -0.212em; padding-right: 0.071em;"><span id="MJXc-Node-5" class="mjx-mi" style=""><span class="mjx-char MJXc-TeX-math-I" style="padding-top: 0.43em; padding-bottom: 0.27em;">i</span></span></span></span><span id="MJXc-Node-6" class="mjx-mo MJXc-space3"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.056em; padding-bottom: 0.323em;">=</span></span><span id="MJXc-Node-7" class="mjx-mo MJXc-space3"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.483em; padding-bottom: 0.59em;">(</span></span><span id="MJXc-Node-8" class="mjx-msubsup"><span class="mjx-base"><span id="MJXc-Node-9" class="mjx-mi"><span class="mjx-char MJXc-TeX-math-I" style="padding-top: 0.216em; padding-bottom: 0.483em;">p</span></span></span><span class="mjx-sub" style="font-size: 70.7%; vertical-align: -0.212em; padding-right: 0.071em;"><span id="MJXc-Node-10" class="mjx-mi" style=""><span class="mjx-char MJXc-TeX-math-I" style="padding-top: 0.43em; padding-bottom: 0.27em;">i</span></span></span></span><span id="MJXc-Node-11" class="mjx-mo MJXc-space2"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.323em; padding-bottom: 0.43em;">+</span></span><span id="MJXc-Node-12" class="mjx-mi MJXc-space2"><span class="mjx-char MJXc-TeX-math-I" style="padding-top: 0.483em; padding-bottom: 0.27em;">k</span></span><span id="MJXc-Node-13" class="mjx-mo"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.483em; padding-bottom: 0.59em;">)</span></span><span id="MJXc-Node-14" class="mjx-mo" style="padding-left: 0.278em; padding-right: 0.278em;"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.43em; padding-bottom: 0.377em;">mod</span></span><span id="MJXc-Node-15" class="mjx-mn"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.377em; padding-bottom: 0.377em;">26</span></span></span></span></span></span><script type="math/tex; mode=display" id="MathJax-Element-1">c_i = (p_i + k) \bmod 26</script>
</div>
</div>
<div class="paragraph">
<p>wherein <span class="MathJax_Preview" style="display: none;"></span><span id="MathJax-Element-2-Frame" class="mjx-chtml MathJax_CHTML" tabindex="0" style="font-size: 117%;"><span id="MJXc-Node-16" class="mjx-math"><span id="MJXc-Node-17" class="mjx-mrow"><span id="MJXc-Node-18" class="mjx-mo" style="padding-left: 0.278em; padding-right: 0.278em;"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.43em; padding-bottom: 0.377em;">mod</span></span><span id="MJXc-Node-19" class="mjx-mn"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.377em; padding-bottom: 0.377em;">26</span></span></span></span></span><script type="math/tex" id="MathJax-Element-2">\bmod 26</script> here means "remainder when dividing by 26." This formula perhaps makes the cipher seem more complicated than it is, but it’s really just a concise way of expressing the algorithm precisely.</p>
</div>
</div>
</div>
<div class="sect1">
<h2 id="specification"><a class="link" href="#specification">Specification</a></h2>
<div class="sectionbody">
<div class="paragraph">
<p>Design and implement a program, <code>caesar</code>, that encrypts messages using Caesar’s cipher.</p>
</div>
<div class="ulist">
<ul>
<li>
<p>Implement your program in a file called <code>caesar.c</code> in a directory called <code>caesar</code>.</p>
</li>
<li>
<p>Your program must accept a single command-line argument, a non-negative integer. Let’s call it <em>k</em> for the sake of discussion.</p>
</li>
<li>
<p>If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with <code>printf</code>) and return from <code>main</code> a value of <code>1</code> (which tends to signify an error) immediately.</p>
</li>
<li>
<p>You can assume that, if a user does provide a command-line argument, it will be a non-negative integer (e.g., <code>1</code>). No need to check that it’s indeed numeric.</p>
</li>
<li>
<p>Do not assume that <em>k</em> will be less than or equal to 26. Your program should work for all non-negative integral values of <em>k</em> less than 2<sup>31</sup> - 26. In other words, you don’t need to worry if your program eventually breaks if the user chooses a value for <em>k</em> that’s too big or almost too big to fit in an <code>int</code>. (Recall that an <code>int</code> can overflow.) But, even if <em>k</em> is greater than 26, alphabetical characters in your program’s input should remain alphabetical characters in your program’s output. For instance, if <em>k</em> is 27, <code>A</code> should not become <code>[</code> even though <code>[</code> is 27 positions away from <code>A</code> in ASCII, per <a href="http://www.asciichart.com/">asciichart.com</a>; <code>A</code> should become <code>B</code>, since <code>B</code> is 27 positions away from <code>A</code>, provided you wrap around from <code>Z</code> to <code>A</code>.</p>
</li>
<li>
<p>Your program must output <code>plaintext:</code> (without a newline) and then prompt the user for a <code>string</code> of plaintext (using <code>get_string</code>).</p>
</li>
<li>
<p>Your program must output <code>ciphertext:</code> (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext "rotated" by <em>k</em> positions; non-alphabetical characters should be outputted unchanged.</p>
</li>
<li>
<p>Your program must preserve case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated, must remain lowercase letters.</p>
</li>
<li>
<p>After outputting ciphertext, you should print a newline. Your program should then exit by returning <code>0</code> from <code>main</code>.</p>
</li>
</ul>
</div>
</div>
</div>
<div class="sect1">
<h2 id="usage"><a class="link" href="#usage">Usage</a></h2>
<div class="sectionbody">
<div class="paragraph">
<p>Your program should behave per the examples below. Assumed that the underlined text is what some user has typed.</p>
</div>
<div class="listingblock">
<div class="content">
<pre class="pygments highlight"><code>$ <span class="underline">./caesar 1</span>
plaintext:  <span class="underline">HELLO</span>
ciphertext: IFMMP</code></pre>
</div>
</div>
<div class="listingblock">
<div class="content">
<pre class="pygments highlight"><code>$ <span class="underline">./caesar 13</span>
plaintext:  <span class="underline">hello, world</span>
ciphertext: uryyb, jbeyq</code></pre>
</div>
</div>
<div class="listingblock">
<div class="content">
<pre class="pygments highlight"><code>$ <span class="underline">./caesar 13</span>
plaintext:  <span class="underline">be sure to drink your Ovaltine</span>
ciphertext: or fher gb qevax lbhe Binygvar</code></pre>
</div>
</div>
<div class="listingblock">
<div class="content">
<pre class="pygments highlight"><code>$ <span class="underline">./caesar</span>
Usage: ./caesar k</code></pre>
</div>
</div>
<div class="listingblock">
<div class="content">
<pre class="pygments highlight"><code>$ <span class="underline">./caesar 1 2 3 4 5</span>
Usage: ./caesar k</code></pre>
</div>
</div>
</div>
</div>
