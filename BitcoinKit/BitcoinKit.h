//
//  BitcoinKit.h
//
//  Copyright © 2018 Kishikawa Katsumi
//  Copyright © 2018 BitcoinKit developers
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <UIKit/UIKit.h>

FOUNDATION_EXPORT double BitcoinKitVersionNumber;
FOUNDATION_EXPORT const unsigned char BitcoinKitVersionString[];
git@vger.kernel.org list mirror (unofficial, one of many)
 help / color / Atom feed
From: Max Rothman <max.r.rothman@gmail.com>
To: git@vger.kernel.org
Subject: Re: [PATCH] completion: add missing completions for log, diff, show
Date: Thu, 1 Aug 2019 20:54:05 -0400
Message-ID: <CAFA_24J8Ry5LhRX5O82eJDtrqjEodDFTEniZNw06fKEWvwvYMA@mail.gmail.com> (raw)
In-Reply-To: <0102016bb065bf5e-005b0752-2594-45d5-a01a-12d0c5e24b70-000000@eu-west-1.amazonses.com>

Ping :)


On Thu, Aug 1, 2019 at 8:50 PM Max Rothman <max.r.rothman@gmail.com> wrote:
>
> The bash completion script knows some options to "git log" and
> "git show" only in the positive form, (e.g. "--abbrev-commit"), but not
> in their negative form (e.g. "--no-abbrev-commit"). Add them.
>
> Also, the bash completion script is missing some other options to
> "git diff", and "git show" (and thus, all other commands that take
> "git diff"'s options). Add them. Of note, since "--indent-heuristic" is
> no longer experimental, add that too.
>
> Signed-off-by: Max Rothman <max.r.rothman@gmail.com>
> ---
>  contrib/completion/git-completion.bash | 18 ++++++++++++++----
>  1 file changed, 14 insertions(+), 4 deletions(-)
>
> diff --git a/contrib/completion/git-completion.bash b/contrib/completion/git-completion.bash
> index 9f71bcde967bc..b6d18710135ec 100644
> --- a/contrib/completion/git-completion.bash
> +++ b/contrib/completion/git-completion.bash
> @@ -1474,6 +1474,8 @@ __git_diff_common_options="--stat --numstat --shortstat --summary
>                         --dirstat-by-file= --cumulative
>                         --diff-algorithm=
>                         --submodule --submodule= --ignore-submodules
> +                       --indent-heuristic --no-indent-heuristic
> +                       --textconv --no-textconv
>  "
>
>  _git_diff ()
> @@ -1782,6 +1784,10 @@ _git_log ()
>                 __gitcomp "$__git_diff_submodule_formats" "" "${cur##--submodule=}"
>                 return
>                 ;;
> +       --no-walk=*)
> +               __gitcomp "sorted unsorted" "" "${cur##--no-walk=}"
> +               return
> +               ;;
>         --*)
>                 __gitcomp "
>                         $__git_log_common_options
> @@ -1789,16 +1795,19 @@ _git_log ()
>                         $__git_log_gitk_options
>                         --root --topo-order --date-order --reverse
>                         --follow --full-diff
> -                       --abbrev-commit --abbrev=
> +                       --abbrev-commit --no-abbrev-commit --abbrev=
>                         --relative-date --date=
>                         --pretty= --format= --oneline
>                         --show-signature
>                         --cherry-mark
>                         --cherry-pick
>                         --graph
> -                       --decorate --decorate=
> +                       --decorate --decorate= --no-decorate
>                         --walk-reflogs
> +                       --no-walk --no-walk= --do-walk
>                         --parents --children
> +                       --expand-tabs --expand-tabs= --no-expand-tabs
> +                       --patch
>                         $merge
>                         $__git_diff_common_options
>                         --pickaxe-all --pickaxe-regex
> @@ -2525,8 +2534,9 @@ _git_show ()
>                 return
>                 ;;
>         --*)
> -               __gitcomp "--pretty= --format= --abbrev-commit --oneline
> -                       --show-signature
> +               __gitcomp "--pretty= --format= --abbrev-commit --no-abbrev-commit
> +                       --oneline --show-signature --patch
> +                       --expand-tabs --expand-tabs= --no-expand-tabs
>                         $__git_diff_common_options
>                         "
>                 return
>
> --
> https://github.com/git/git/pull/426
>
next prev parent reply index

Thread overview: 16+ messages / expand[flat|nested]  mbox.gz  Atom feed  top
2017-10-11 14:47 No log --no-decorate completion? Max Rothman
2017-10-11 18:09 ` Stefan Beller
2017-10-12 17:41   ` Max Rothman
2017-10-24 15:32     ` Max Rothman
     [not found]     ` <CAFA_24K99LkeJBKV7+a-m-m9PUZik49cOd40+cEn-6zCvGmMsQ@mail.gmail.com>
2017-10-24 15:32       ` Stefan Beller
2017-11-02 20:25         ` Max Rothman
2017-11-02 21:19           ` Stefan Beller
2017-11-07 20:31             ` Max Rothman
2017-11-07 20:48               ` Stefan Beller
2017-11-07 21:22                 ` [PATCH] completion: add missing completions for log, diff, show Max Rothman
2017-11-08  2:33                   ` Junio C Hamano
2017-11-08  3:30                     ` Max Rothman
2017-11-08  4:06                       ` Junio C Hamano
2019-07-02  1:56                   ` Max Rothman
2019-08-02  0:54                     ` Max Rothman [this message]
2019-09-11 18:15                       ` Max Rothman
Reply instructions:

You may reply publically to this message via plain-text email
using any one of the following methods:

* Save the following mbox file, import it into your mail client,
  and reply-to-all from there: mbox

  Avoid top-posting and favor interleaved quoting:
  https://en.wikipedia.org/wiki/Posting_style#Interleaved_style

  List information: http://vger.kernel.org/majordomo-info.html

* Reply using the --to, --cc, and --in-reply-to
  switches of git-send-email(1):

  git send-email \
    --in-reply-to=CAFA_24J8Ry5LhRX5O82eJDtrqjEodDFTEniZNw06fKEWvwvYMA@mail.gmail.com \
    --to=max.r.rothman@gmail.com \
    --cc=git@vger.kernel.org \
    /path/to/YOUR_REPLY

  https://kernel.org/pub/software/scm/git/docs/git-send-email.html

* If your mail client supports setting the In-Reply-To header
  via mailto: links, try the mailto: link
git@vger.kernel.org list mirror (unofficial, one of many)

Archives are clonable:
	git clone --mirror https://public-inbox.org/git
	git clone --mirror http://ou63pmih66umazou.onion/git
	git clone --mirror http://czquwvybam4bgbro.onion/git
	git clone --mirror http://hjrcffqmbrq6wope.onion/git

Newsgroups are available over NNTP:
	nntp://news.public-inbox.org/inbox.comp.version-control.git
	nntp://ou63pmih66umazou.onion/inbox.comp.version-control.git
	nntp://czquwvybam4bgbro.onion/inbox.comp.version-control.git
	nntp://hjrcffqmbrq6wope.onion/inbox.comp.version-control.git
	nntp://news.gmane.org/gmane.comp.version-control.git

 note: .onion URLs require Tor: https://www.torproject.org/

AGPL code for this site: git clone https://public-inbox.org/ public-inbox
