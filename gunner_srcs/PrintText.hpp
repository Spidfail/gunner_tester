#ifndef PRINTTEXT_HPP
# define PRINTTEXT_HPP

# include <iostream>
# include <sstream>

namespace print {
	enum	Color {
		BLACK	=	30,
		RED     =	31,
		GREEN   =	32,
		YELLOW  =	33,
		BLUE    =	34,
		MAGENTA =	35,
		CYAN    =	36,
		WHITE   =	37
	};

	enum	Background {
		B_BLACK	  =	40,
		B_RED     =	41,
		B_GREEN   =	42,
		B_YELLOW  =	43,
		B_BLUE    =	44,
		B_MAGENTA =	45,
		B_CYAN    =	46,
		B_WHITE   =	47
	};

	enum	Modifiyer {
		M_NOTHING	   =	-1,
		RESET          =	 0,
		BOLD      	   =	 1,
		UNDERLINE      =	 4,
		INVERSE        =	 7,
		BOLD_OFF  	   =	21,
		UNDERLINE_OFF  =	24,
		INVERSE_OFF    =	27
	};

	template <typename T>
	class	PrintText {
		private:
			std::ostream	&_stream;
			Color			_text;
			Background		_background;
			Modifiyer		_mod;

		public:
			typedef		T			value_type;
			typedef		Color		text_type;
			typedef		Background	background_type;
			typedef		Modifiyer	mod_type;

			PrintText()
				: _stream(std::cout), _text(WHITE), _background(B_BLACK), _mod(M_NOTHING) { }

			~PrintText() { }

			PrintText(const PrintText &source) { *this = source; }

			PrintText(std::ostream &os, const text_type &text,
					const background_type &background = B_BLACK, const mod_type mod = M_NOTHING)
				: _stream(os), _text(text), _background(background), _mod(mod) { }

			PrintText	&operator=(const PrintText &source) {
				_stream = source._stream;
				_text = source._text;
				_background = source._background;
				_mod = source._mod;
			}

			void		operator()(const value_type &output) {
				std::stringstream ss;
				ss << "\033[" << _text << ";" << _background;
				if (_mod != M_NOTHING)
					ss << ";" << _mod;
				ss << "m";
				ss << output << "\033[0m";
				_stream << ss.str();
			}
			
			void		set_text(const text_type &text) { _text = text; }
			void		set_background(const background_type &background) { _background = background; }
			void		set_mod(const mod_type &mod) { _mod = mod; }
			void		set_parameters(const text_type &text, const background_type &background = B_BLACK,
					const mod_type mod = RESET) {
				_text = text;
				_background = background;
				_mod = mod;
			}
	};
}

#endif
