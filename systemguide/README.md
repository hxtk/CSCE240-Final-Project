# Contributing to the System Guide

The System Guide shall consist of chapters in discrete files. Simply create a file with a descriptive name. Give it a commented copyright header for Group 7, including the date, followed by a commented description of the content in one or two sentences.

If you've never used LaTeX before, [WikiBooks has a good book on it](https://en.wikibooks.org/wiki/LaTeX/). For quick reference, the following self-descriptive dividers exist:

`\chapter{...}`

`\section{...}`

`\subsection{...}`

`\subsubsection{...}`

Where the text between the braces is the title of the respective chapter/section/etc.

A LaTeX comment is a percent sign (`%`). If you need a literal percent sign, or other special character, escape it with a backslash (`\%`).

--------------

A list of things in order is as follows:

    \begin{enumerate}
    \item ....
    \item ....
    ....
    \end{enumerate}

-------------

A list of things not in order is as follows:

     \begin{itemize}
     \item ...
     \item ...
     ...
     \end{itemize}

---------------

A set of definitions can be made as follows:

    \begin{description}
    \item[name1] description1
    \item[name2] description2
    \end{description}

-------------------

Short pieces of code should be put in `\texttt{...}`

Longer pieces of code should be as follows:

     \begin{lstlisting}[language=C++]
     ...
     \end{lstlisting}


