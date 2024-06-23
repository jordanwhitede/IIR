IIR : UGen {
	*ar { |input, a1, b0, b1|
		^this.multiNew('audio', input, a1, b0, b1);
	}
	checkInputs {
		^this.checkValidInputs;
	}
}
